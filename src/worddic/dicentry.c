#include "dicentry.h"

GjitenDicentry* parse_line(gchar* line){
  gchar *line_cpy = strdup(line);
  GjitenDicentry* dicentry = g_new0 (GjitenDicentry, 1);

  //cut until / 
  gchar *chunk = strtok(line_cpy, "/");
  
  //read the definitions
  dicentry->definitions = NULL;
  gchar *definition = strtok(NULL, "/");
  do{
    if(definition && strcmp(definition, "\n")){
      dicentry->definitions = g_list_append(dicentry->definitions,
                                            g_strdup_printf("%s", definition));
      }
    definition = strtok(NULL, "/");
  }while(definition);
  
  dicentry->jap_definition = g_strdup_printf("%s", strtok(chunk, " "));

  gchar* reading = strtok(NULL, " ");
  if(reading){
    dicentry->jap_reading = g_strdup_printf("%s", reading);
    //trim the bracets []
    size_t len = strlen(dicentry->jap_reading);
    memmove(dicentry->jap_reading, dicentry->jap_reading+1, len-2);
    dicentry->jap_reading[len-2] = 0;
  }
  else{
    dicentry->jap_reading = NULL;
  }
    
  return dicentry;
}

