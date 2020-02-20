# https://bagder.github.io/libcurl-video-tutorials/setup/

# Sets env variables for the compiler for libcurl and the -lcurl library provided
CC = `curl-config --cc`
LIBS = `curl-config --libs`

# Means the file executable file elastic_search_client_play depends on the files to the right of the colon and then gets
# built if it exists
elastic_search_client_play: elastic_search_client_play.o
	$(CC) -g -o $@ $< $(LIBS)

# So if the .o file does not exist above then build it from the .c file with this command.
elastic_search_client_play.o: elastic_search_client_play.c
	$(CC) -g -c $<

clean:
	rm -f elastic_search_client_play.o elastic_search_client_play