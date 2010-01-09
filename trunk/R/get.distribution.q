get.distribution <- function(domain, node, class = c("data.frame", "table",
                             "ftable", "numeric"))
{
  RHugin.check.args(domain, node, character(0), "get.distribution")
  class <- match.arg(class)

  node.ptr <- .Call("RHugin_domain_get_node_by_name", domain, node,
                     PACKAGE = "RHugin")
  RHugin.handle.error()

  table.ptr <- .Call("RHugin_node_get_distribution", node.ptr,
                      PACKAGE = "RHugin")
  RHugin.handle.error()

  on.exit(.Call("RHugin_table_delete", table.ptr, PACKAGE = "RHugin"))

  node.ptrs <- .Call("RHugin_table_get_nodes", table.ptr, PACKAGE = "RHugin")
  nodes <- names(node.ptrs)

  kinds <- character()

  for(node in nodes) {
    kinds[node] <- .Call("RHugin_node_get_kind", node.ptrs[[node]],
                          PACKAGE = "RHugin")
    RHugin.handle.error()
  }

  discrete <- nodes[kinds == "discrete"]
  continuous <- nodes[kinds == "continuous"]

  states <- lapply(discrete, function(u) get.states(domain, u))
  names(states) <- discrete
  states <- rev(states)
  d <- sapply(states, length)

  table <- .Call("RHugin_table_get_data", table.ptr, PACKAGE = "RHugin")
  RHugin.handle.error()

  n.continuous <- length(continuous)
  n.table <- length(table)

  mean <- NA
  cov <- NA

  if(n.continuous) {
    mean <- matrix(0.0, nrow = n.table, ncol = n.continuous)
    dimnames(mean) <- list(1:n.table, continuous)
    cov <- list()

    for(j in 1:n.continuous)
      mean[ , j] <- .Call("RHugin_table_get_mean", table.ptr,
                           as.integer(0:(n.table - 1)),
                           node.ptrs[[continuous[j]]],
                           PACKAGE = "RHugin")

    for(k in 1:n.table) {
      tmp <- matrix(0.0, n.continuous, n.continuous)
      dimnames(tmp) <- list(continuous, continuous)
      for(i in 1:n.continuous)
        tmp[i, i] <- .Call("RHugin_table_get_variance", table.ptr,
                            as.integer(k - 1), node.ptrs[[continuous[i]]],
                            PACKAGE = "RHugin")

      if(n.continuous > 1) {
        for(i in 2:n.continuous) {
          for(j in 1:(i - 1))
            tmp[i, j] <- tmp[j, i] <- .Call("RHugin_table_get_covariance",
                                             table.ptr, as.integer(k - 1),
                                             node.ptrs[[continuous[i]]],
                                             node.ptrs[[continuous[j]]],
                                             PACKAGE = "RHugin")
        }
      }
    cov[[k]] <- tmp  
    }
  }

  table <- switch(class,
    "data.frame" = {
      table <- cbind(expand.grid(states), table)
      names(table)[length(table)] <- "Freq"
      table
    },

    "table" = {
      attributes(table) <- list(dim = d, dimnames = states, class = "table")
      table
    },

    "ftable" = {
      attributes(table) <- list(dim = d, dimnames = states, class = "table")
      n <- length(table.nodes)
      ftable(table, row.vars = table.nodes[n], col.vars = table.nodes[-n])
    },

    "numeric" = table
  )

  list(table = table, mean = mean, cov = cov)
}


