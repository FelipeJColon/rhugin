\name{get.belief}
\alias{get.belief}

\title{Retrieve Beliefs}

\description{
Retrieve beliefs from a node in an RHugin domain.
}

\usage{
get.belief(domain, node)
}

\arguments{
  \item{domain}{an RHugin domain.}
  \item{node}{a character string specifying the name of the node from which the beliefs are to be retrieved.}
}

\value{
for discrete nodes: a numeric vector containing the belief for each state in \code{node}; for continuous nodes: a numeric vector of length two containing the mean and the variance of the marginal distribution.
}

\references{
HUGIN API Reference Manual \url{http://download.hugin.com/webdocs/manuals/api-manual.pdf}: \code{h_node_get_belief}, \code{h_node_get_mean} and \code{h_node_get_variance}.
}

\author{Kjell Konis \email{kjell.konis@icloud.com}}

\examples{
demo("apple", echo = FALSE)

# Compile the domain
compile(apple)

# Select state
set.finding(apple, "Loses", "yes")

# Propagate and get beliefs
propagate(apple)
get.belief(apple, "Sick")
}

\keyword{programming}


