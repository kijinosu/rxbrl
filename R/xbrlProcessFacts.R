## rxbrl -  Extraction of Business Financial Information from 'XBRL' Documents
## Copyright (C) 2014-2016 Roberto Bertolusso, 2025 Alan Engel

## This file is part of rxbrl and was adapted from XBRL.
##
## rxbrl is free software: you can redistribute it and/or modify it
## under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 2 of the License, or
## (at your option) any later version.
##
## rxbrl is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with rxbrl. If not, see <http://www.gnu.org/licenses/>.


xbrlProcessFacts <- function(doc) {
  .Call("xbrlProcessFacts", doc, PACKAGE="rxbrl")
}
