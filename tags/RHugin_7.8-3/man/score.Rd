\name{score}
\alias{score}

\title{Score}

\description{
Compute the log-likelihood, AIC and BIC of the cases (data) given the model.
}

\usage{
score(domain, measure = c("log-likelihood", "AIC", "BIC"))
}

\arguments{
  \item{domain}{an RHugin domain.}
  \item{measure}{a character vector indicating which score measures to compute. All valid choice are given in the function call.}
}

\details{
The \emph{Scoring of graphical models} section of the HUGIN API Reference Manual describes how each of these quantities is computed.
}

\value{
a named numeric vector containing the scores.
}

\references{
HUGIN API Reference Manual \url{http://download.hugin.com/webdocs/manuals/api-manual.pdf}: \code{h_domain_get_log_likelihood}, \code{h_domain_get_AIC} and \code{h_domain_get_BIC}.
}

\author{Kjell Konis \email{kjell.konis@icloud.com}}

\examples{
demo("asia", echo = FALSE)

# The cases from example 11.1 in the Hugin API Manual
asia.dat <- data.frame(
  Asia = c("yes", "no", "no", "no", "yes", "yes", "yes", "no"),
  Smoking = c("no", "yes", "yes", "no", "yes", "no", "yes", "no"),
  Dyspnoea = c("no", "yes", "yes", "yes", NA, "no", "yes", "no"),
  XRay = c("no", "no", "yes", "yes", "no", NA, "yes", NA),
  Freq = c(1, 1, 1, 1, 2, 1, 1, 1))

# Compile the domain
compile(asia)

# Add cases
set.cases(asia, asia.dat, "Freq")

# Compute scores
score(asia)
}

\keyword{programming}


