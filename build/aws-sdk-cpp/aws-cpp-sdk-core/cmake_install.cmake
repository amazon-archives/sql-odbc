# Install script for directory: /Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/lib64/libaws-cpp-sdk-core.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-cpp-sdk-core.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-cpp-sdk-core.a")
    execute_process(COMMAND "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libaws-cpp-sdk-core.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/AmazonSerializableWebServiceRequest.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/AmazonStreamingWebServiceRequest.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/AmazonWebServiceRequest.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/AmazonWebServiceResult.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/Aws.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/Core_EXPORTS.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/Globals.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/NoResult.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/Region.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/SDKConfig.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/Version.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/VersionConfig.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/auth" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/AWSAuthSigner.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/AWSAuthSignerProvider.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/AWSCredentials.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/AWSCredentialsProvider.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/AWSCredentialsProviderChain.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/auth/STSCredentialsProvider.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/client" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/AWSClient.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/AWSError.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/AWSErrorMarshaller.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/AsyncCallerContext.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/ClientConfiguration.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/CoreErrors.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/DefaultRetryStrategy.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/RetryStrategy.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/client/SpecifiedRetryableErrorsRetryStrategy.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/internal" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/internal/AWSHttpResourceClient.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/net" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/net/Net.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/net/SimpleUDP.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/http" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/HttpClient.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/HttpClientFactory.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/HttpRequest.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/HttpResponse.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/HttpTypes.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/Scheme.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/URI.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/http/standard" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/standard/StandardHttpRequest.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/standard/StandardHttpResponse.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/config" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/config/AWSProfileConfigLoader.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/monitoring" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/CoreMetrics.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/DefaultMonitoring.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/HttpClientMetrics.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/MonitoringFactory.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/MonitoringInterface.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/monitoring/MonitoringManager.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/platform" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/Android.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/Environment.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/FileSystem.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/OSVersionInfo.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/Platform.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/Security.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/platform/Time.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/ARN.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/Array.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/Cache.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/ConcurrentCache.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/DNS.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/DateTime.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/EnumParseOverflowContainer.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/FileSystemUtils.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/GetTheLights.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/HashingUtils.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/Outcome.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/ResourceManager.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/StringUtils.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/UUID.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/UnreferencedParam.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/event" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventDecoderStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventEncoderStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventHeader.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventMessage.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStreamBuf.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStreamDecoder.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStreamEncoder.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStreamErrors.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/event/EventStreamHandler.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/base64" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/base64/Base64.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/crypto" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/Cipher.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/ContentCryptoMaterial.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/ContentCryptoScheme.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/CryptoBuf.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/CryptoStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/EncryptionMaterials.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/Factories.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/HMAC.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/Hash.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/HashResult.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/KeyWrapAlgorithm.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/MD5.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/SecureRandom.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/Sha256.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/Sha256HMAC.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/json" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/json/JsonSerializer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/xml" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/xml/XmlSerializer.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/logging" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/AWSLogging.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/ConsoleLogSystem.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/DefaultLogSystem.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/FormattedLogSystem.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/LogLevel.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/LogMacros.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/LogSystemInterface.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/logging/NullLogSystem.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/memory" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/AWSMemory.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/MemorySystemInterface.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/memory/stl" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSAllocator.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSDeque.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSList.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSMap.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSMultiMap.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSQueue.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSSet.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSStack.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSStreamFwd.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSString.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSStringStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/AWSVector.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/memory/stl/SimpleStringStream.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/ratelimiter" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/ratelimiter/DefaultRateLimiter.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/ratelimiter/RateLimiterInterface.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/stream" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/stream/ConcurrentStreamBuf.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/stream/PreallocatedStreamBuf.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/stream/ResponseStream.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/stream/SimpleStreamBuf.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/threading" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/threading/Executor.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/threading/ReaderWriterLock.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/threading/Semaphore.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/threading/ThreadTask.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/external/cjson" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/external/cjson/cJSON.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/external/tinyxml2" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/external/tinyxml2/tinyxml2.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/http/curl" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/curl/CurlHandleContainer.h"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/http/curl/CurlHttpClient.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/aws/core/utils/crypto/commoncrypto" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/src/aws-sdk-cpp/aws-cpp-sdk-core/include/aws/core/utils/crypto/commoncrypto/CryptoImpl.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets.cmake"
         "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/aws-cpp-sdk-core/CMakeFiles/Export/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/aws-cpp-sdk-core/CMakeFiles/Export/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core" TYPE FILE FILES "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/aws-cpp-sdk-core/CMakeFiles/Export/lib/cmake/aws-cpp-sdk-core/aws-cpp-sdk-core-targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/aws-cpp-sdk-core" TYPE FILE FILES
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/aws-cpp-sdk-core/aws-cpp-sdk-core-config.cmake"
    "/Users/jordanw/Development/Projects/Amazon/ESODBC/build/aws-sdk-cpp/aws-cpp-sdk-core/aws-cpp-sdk-core-config-version.cmake"
    )
endif()

