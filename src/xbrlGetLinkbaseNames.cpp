// rxbrl -  Extraction of Business Financial Information from 'XBRL' Documents
// Copyright (C) 2014-2016 Roberto Bertolusso, 2025 Alan Engel

// This file is part of rxbrl and is adapted from XBRL.
// 
// rxbrl is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// at your option) any later version.
// 
// rxbrl is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with rxbrl. If not, see <http://www.gnu.org/licenses/>.

#include "rxbrl.h"


RcppExport SEXP xbrlGetLinkbaseNames(SEXP epaDoc) {
  xmlDocPtr doc = (xmlDocPtr) R_ExternalPtrAddr(epaDoc);
  
  xmlXPathContextPtr context = xmlXPathNewContext(doc);
  xmlXPathObjectPtr linkbaseRef_res = xmlXPathEvalExpression((xmlChar*) "//*[local-name()='linkbaseRef']", context);
  xmlNodeSetPtr linkbaseRef_nodeset = linkbaseRef_res->nodesetval;
  xmlXPathFreeContext(context);
  
  int linkbaseRef_nodeset_ln = linkbaseRef_nodeset->nodeNr;
  
  CharacterVector href(linkbaseRef_nodeset_ln);
  
  for (int i=0; i < linkbaseRef_nodeset_ln; i++) {
    xmlNodePtr linkbaseRef_node = linkbaseRef_nodeset->nodeTab[i];
    
    xmlChar *tmp_str;
    if ((tmp_str = xmlGetProp(linkbaseRef_node, (xmlChar*) "href"))) { 
      href[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      href[i] = NA_STRING;
    }
  }
  xmlXPathFreeObject(linkbaseRef_res);
  
  return href;
}
