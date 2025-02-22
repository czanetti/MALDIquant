\name{trim-methods}
\docType{methods}
\alias{trim}
\alias{trim,AbstractMassObject,numeric-method}
\alias{trim,list,numeric-method}
\alias{trim,list,missing-method}
\title{Trim an AbstractMassObject object.}
\description{
This method trims an \code{\linkS4class{AbstractMassObject}} object.
That is useful if some mass ranges should be excluded from further analysis.
}
\usage{
\S4method{trim}{AbstractMassObject,numeric}(object, range)
\S4method{trim}{list,numeric}(object, range, \dots)
\S4method{trim}{list,missing}(object, range, \dots)
}
\arguments{
  \item{object}{\code{\linkS4class{AbstractMassObject}} object or a
    \code{list} of \code{\linkS4class{AbstractMassObject}} objects.}
  \item{range}{\code{numeric}, limits of trimming (left/minimal mass,
    right/maximal mass). If missing it is automatically determined (largest
    overlapping mass range) for a \code{list} of
    \code{\linkS4class{AbstractMassObject}}.}
  \item{\dots}{arguments to be passed to underlying functions (currently only
    \code{mc.cores} is supported).}
}
\author{
Sebastian Gibb \email{mail@sebastiangibb.de}
}
\seealso{
\code{\linkS4class{AbstractMassObject}},
\code{\linkS4class{MassPeaks}},
\code{\linkS4class{MassSpectrum}}

Website: \url{https://www.strimmerlab.org/software/maldiquant/}
}
\examples{
## load package
library("MALDIquant")

## load example data
data("fiedler2009subset", package="MALDIquant")

## select only one spectrum
s <- fiedler2009subset[[1]]

## remove all mass lower 3000
trim(s, range=c(3000, Inf))

## remove all mass higher 8000
trim(s, range=c(0, 8000))

## remove all mass lower 3000 and higher 8000
trim(s, range=c(3000, 8000))

## choose largest overlapping mass range for all spectra
trim(fiedler2009subset)
}
\keyword{methods}

