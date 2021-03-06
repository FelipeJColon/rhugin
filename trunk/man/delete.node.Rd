\name{delete.node}
\alias{delete.node}

\title{Delete Node}

\description{
Delete a node from an RHugin domain.
}

\usage{
delete.node(domain, node)
}

\arguments{
  \item{domain}{an RHugin domain.}
  \item{node}{a character vector specifying the names of the node(s) to be deleted.}
}

\details{
All of the edges in the RHugin domain involving \code{node} are deleted as well.  If \code{node} has any children their conditional probability tables (CPT) are adjusted: if \code{node} is discrete, the contents of the updated table will be the portion of the old CPT corresponding to \code{node} being in the first state; if \code{node} is continuous, the beta parameters for the \code{node -> child} edge will be deleted from the table.  Finally, \code{domain} is uncompiled by this operation.
}

\value{
a \code{NULL} value is invisibly returned.
}

\references{
HUGIN API Reference Manual \url{http://download.hugin.com/webdocs/manuals/api-manual.pdf}: \code{h_node_delete}.
}

\author{Kjell Konis \email{kjell.konis@icloud.com}}

\examples{
# Create an RHugin domain
apple <- hugin.domain()

# Add nodes
add.node(apple, "Sick", states = c("yes", "no"))
add.node(apple, "Dry", states = c("yes", "no"))
add.node(apple, "Loses", states = c("yes", "no"))

# Delete the node Dry
delete.node(apple, "Dry")
}

\keyword{programming}


