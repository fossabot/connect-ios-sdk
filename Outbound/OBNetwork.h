//
//  OBNetwork.h
//  Outbound
//
//  Created by Emilien on 2015-04-19.
//  Copyright (c) 2015 Outbound.io. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 OBNetwork provides methods to perform HTTP requests to Outbound API.
 */
@interface OBNetwork : NSObject

/**-----------------------------------------------------------------------------
 * @name Public methods
 * -----------------------------------------------------------------------------
 */

/**
 @abstract Performs a POST call to an Outbound API endpoint.
 @param path API call path. Possible paths as defined by the [Outbound API](https://github.com/outboundio/api) are `identify`, `track`, `apns/register`, `apns/disable`.
 @param key Host app API key.
 @param params API call parameters.
 @param completion A block to be executed after the request was performed. Passes the HTTP status code of the response, and either an error or a response object.
 @discussion The POST request itself is generated by the private +postRequestWithPath:APIKey:parameters:andError: method, which builds the POST body and insert the necessary headers. Then the request is sent asynchronously using [NSURLConnection](https://developer.apple.com/library/prerelease/ios/documentation/Cocoa/Reference/Foundation/Classes/NSURLConnection_Class/index.html). If the request is successful, the JSON response is deserialized into an NSObject and passed to the completion block. Otherwise, an error is passed instead.
 */
+ (void)postPath:(NSString *)path withAPIKey:(NSString *)key parameters:(NSDictionary *)params andCompletion:(void (^)(NSInteger statusCode, NSError *error, NSObject *response))completion;

/**
 @abstract Performs a GET call to an Outbound API endpoint.
 @param path API call path. Possible paths as defined by the [Outbound API](https://github.com/outboundio/api) are `identify`, `track`, `apns/register`, `apns/disable`.
 @param key Host app API key.
 @param completion A block to be executed after the request was performed. Passes the HTTP status code of the response, and either an error or a response object.
 @discussion If any GET parameters are needed, they should be included in the `path`. The request is sent asynchronously using [NSURLConnection](https://developer.apple.com/library/prerelease/ios/documentation/Cocoa/Reference/Foundation/Classes/NSURLConnection_Class/index.html). If the request is successful, the JSON response is deserialized into an NSObject and passed to the completion block. Otherwise, an error is passed instead.
 */
+ (void)getPath:(NSString *)path withAPIKey:(NSString *)key andCompletion:(void (^)(NSInteger statusCode, NSError *error, NSObject *response))completion;

/**
 Helper method to create a unique ID.
 */
+ (NSString *)uuid;

@end