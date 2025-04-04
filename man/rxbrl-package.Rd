\name{rxbrl-package}
\alias{rxbrl-package}
\alias{rxbrl}
\docType{package}
\title{
  Extraction of business financial information from XBRL documents.
}
\description{
  This package was forked from Roberto Bertulosso's XBRL package 
  <https://github.com/cran/XBRL>.
  
  Functions to extract business financial information from
  an Extensible Business Reporting Language (XBRL) instance file and the
  associated collection of files that defines its Discoverable Taxonomy
  Set (DTS), usually disseminated across different remote locations.

  XBRL documents employ many technologies defined by XML standards, such
  as XML Schema, Namespaces, XLink, and XPath, which make the extraction
  of information involved. The functions provided by this package
  address this complexity, returning data frames containing the enclosed
  information readily available to perform analyses.

  XBRL has been successfully tested in analyzing 10-K and 10-Q
  submissions from USA filing companies that are publicly available at
  the EDGAR system of the Securities and Exchange Commission (SEC).
  It has been reported to work with inline XBRL documents.

  As published taxonomy files (such as
  "http://xbrl.fasb.org/us-gaap/2013/elts/us-gaap-2013-01-31.xsd") 
  are immutable and are used by most filers, XBRL offers the option of
  downloading them only the first time they are referred, keeping a
  local cache copy that can be used from then on. This speeds-up the
  process, specially on slow connections.

  XBRL is not and does not aim to be (at least yet) a validating XBRL
  processor.

  XBRL is still a work in progress. As such, functions and produced data
  frames may change structure in future versions until stabilization.
}
\details{
  This section should provide a more detailed overview of how to use the
  package, including the most important functions.
}
\author{
Alan Engel, Roberto Bertolusso and Marek Kimmel.

Maintainer: Alan Engel <kijinosu@proton.me>
}
\references{
  <https://github.com/cran/XBRL>
}
\keyword{ package XBRL XML }
\seealso{
  \code{\link{XBRL}}
}
\examples{
}


