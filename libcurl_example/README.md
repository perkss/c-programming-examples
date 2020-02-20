# CURL With C

This folder contains examples of `libcurl` connecting to and querying ElasticSearch.


## Getting Started

To test this out. Run `make` to make the project.

Start up Elastic and Kibana with `docker-compose up -d`

Then run the built file `./elastic_search_client_play`

To PUT a document and query it.

The document PUT is 

```json
{
  "id": 1,
  "name": "hotel"
}
```

Returned document is 
```json
{
  "_index" : "chocolate",
  "_type" : "_doc",
  "_id" : "1",
  "_version" : 1,
  "_seq_no" : 1,
  "_primary_term" : 1,
  "found" : true,
  "_source" : {
    "id" : 1,
    "name" : "hotel"
  }
}
```

Then clean up the generated executable with `make clean`