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


RcppExport SEXP xbrlProcessFacts(SEXP epaDoc) {
  xmlDocPtr doc = (xmlDocPtr) R_ExternalPtrAddr(epaDoc);
  
  xmlXPathContextPtr context = xmlXPathNewContext(doc);
  xmlXPathObjectPtr fact_res = xmlXPathEvalExpression((xmlChar*) "//*[@*[local-name()='contextRef']]", context);
  xmlNodeSetPtr fact_nodeset = fact_res->nodesetval;
  xmlXPathFreeContext(context);
  
  int fact_nodeset_ln = fact_nodeset->nodeNr;
  
  CharacterVector elementId(fact_nodeset_ln);
  CharacterVector contextId(fact_nodeset_ln);
  CharacterVector unitId(fact_nodeset_ln);
  CharacterVector fact(fact_nodeset_ln);
  CharacterVector decimals(fact_nodeset_ln);
  CharacterVector sign(fact_nodeset_ln);
  CharacterVector scale(fact_nodeset_ln);
  CharacterVector factId(fact_nodeset_ln);
  CharacterVector ns(fact_nodeset_ln);
  
  for (int i=0; i < fact_nodeset_ln; i++) {
    xmlNodePtr fact_node = fact_nodeset->nodeTab[i];
    
    xmlChar *tmp_str;
    if (xmlStrEqual(fact_node->ns->prefix, (xmlChar*) "ix")) {
      if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "name"))) {
        const xmlChar *colon = xmlStrchr((xmlChar*)tmp_str, ':');
        if(colon) {
          int offset = (int)(colon - tmp_str);
          int lenpost = xmlStrlen(tmp_str) - offset - 1;
          elementId[i] = (char *) xmlStrcat(xmlStrcat(xmlStrsub(tmp_str,0,offset), (xmlChar*) "_"),xmlStrsub(tmp_str,offset+1,lenpost));
        } else
          elementId[i] = (char *) tmp_str;
        xmlFree(tmp_str);
      } else {
        elementId[i] = NA_STRING;
      }
    } else if (fact_node->ns->prefix)
      elementId[i] = (char *) ((string) (char *) fact_node->ns->prefix + "_" + (string) (char *) fact_node->name).data();
    else
      elementId[i] = (char *) fact_node->name;
    
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "contextRef"))) { 
      contextId[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      contextId[i] = NA_STRING;
    }
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "unitRef"))) { 
      unitId[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      unitId[i] = NA_STRING;
    }
    if ((tmp_str = xmlNodeListGetString(doc, fact_node->xmlChildrenNode, 1))) {
      fact[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      fact[i] = NA_STRING;
    }
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "decimals"))) { 
      decimals[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      decimals[i] = NA_STRING;
    }
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "scale"))) { 
      scale[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      scale[i] = NA_STRING;
    }
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "sign"))) { 
      sign[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      sign[i] = NA_STRING;
    }
    if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "id"))) { 
      factId[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else if ((tmp_str = xmlGetProp(fact_node, (xmlChar*) "name"))) { 
      factId[i] = (char *) tmp_str;
      xmlFree(tmp_str);
    } else {
      factId[i] = NA_STRING;
    }
    ns[i] = (char *) fact_node->ns->href;
  }
  xmlXPathFreeObject(fact_res);
  
  return DataFrame::create(Named("elementId")=elementId,
                           Named("contextId")=contextId,
                           Named("unitId")=unitId,
                           Named("fact")=fact,
                           Named("decimals")=decimals,
                           Named("scale")=scale,
                           Named("sign")=sign,
                           Named("factId")=factId,
                           Named("ns")=ns);
}
