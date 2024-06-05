// Copyright (c) 2023 Yuki Kimoto
// MIT License

#ifndef SPVM_SOCKET_UTIL_H
#define SPVM_SOCKET_UTIL_H

#include "spvm_native.h"

// This macro will be removed if Sys class does not use it.
#define SPVM_SOCKET_UTIL_DEFINE_SOCKADDR_UN

#ifdef _WIN32
  #include <ws2tcpip.h>
  #include <winsock2.h>
  #include <io.h>
  #include <winerror.h>
  
  #define UNIX_PATH_MAX 108
  struct sockaddr_un {
    ADDRESS_FAMILY sun_family;
    char sun_path[UNIX_PATH_MAX];
  };
#else
  #include <unistd.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <netinet/ip.h>
  #include <netdb.h>
  #include <arpa/inet.h>
  #include <sys/un.h>
#endif

#include <errno.h>

int32_t spvm_socket_errno (void);

void* spvm_socket_strerror_string (SPVM_ENV* env, SPVM_VALUE* stack, int32_t error_number, int32_t length);

const char* spvm_socket_strerror(SPVM_ENV* env, SPVM_VALUE* stack, int32_t error_number, int32_t length);

#endif
