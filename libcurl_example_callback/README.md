# CURL With C and Callbacks

This folder contains examples of `libcurl` connecting to and querying ElasticSearch.

## Requirements
cmake

## Getting Started

To test this out. Run the following commands to make the project.

```bash
mkdir build
cd build
cmake ../../libcurl_example_callback
cmake --build .
```

Start up Elastic and Kibana with `docker-compose up -d`

Then to run the built file in the build directory `libcurl-example-callback`

```bash
./libcurl-example-callback
```

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

Then clean up the generated executable in the build direcotry with `cmake --clean .` and `rm -r build`