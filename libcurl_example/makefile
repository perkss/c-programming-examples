# https://bagder.github.io/libcurl-video-tutorials/setup/

# Sets env variables
CC = `curl-config --cc`
LIBS = `curl-config --libs`

# Means the file mycurlapp depends on the files to the right of the colon
elastic_search_client_play: elastic_search_client_play.o
	$(CC) -g -o $@ $< $(LIBS)

elastic_search_client_play.o: elastic_search_client_play.c
	$(CC) -g -c $<

clean:
	rm -f elastic_search_client_play.o elastic_search_client_play