/*!
 @header LoginRadiusUtilities.h
 
 @brief This class includes the gadgets which might be used to format/parse the string, url, dictionary, api, etc..
 
 @author LoginRadius Team
 @copyright  2015 LoginRadius
 @version    2015-06
 @helps All other classes in the framework.
 */

#import <Foundation/Foundation.h>
#import "LoginRadiusUtilities.h"

@interface LoginRadiusUtilities : NSObject

/*!
 * @function sendSyncGetRequest
 * @brief Send a sync get request to the specified API url being passed in.
 * @param urlString The url address of the API server for the GET API call.
 * @return a NSMutableDictionary object contains the reponse from server.
 */
- (NSMutableDictionary *)sendSyncGetRequest :(NSString *)urlString;
/*!
 * @function createPostAPIRequest
 * @brief Create a POST API call based on the passed in parameters
 * @param endpoint The url of the POST API.
 * @param method @"POST"
 * @param dataLength The length of the data in POST body
 * @param postData The post data in JSON format
 * @warning The header of @"Content-Type" is @"applciation/json"
 * @return a NSMutableRequest request for the POST API call
 */
- (NSMutableURLRequest *)createPostAPIRequest :(NSString *)endpoint :(NSString *)method :(NSString *)dataLength :(NSData *)postData;
/*!
    @function parseDatatoJsonData
    @brief Parse the NSMutableDictionary data into JSON format and return
    @param data The data of the body of the POST call
    @return NSData of the passed in data
 */
- (NSData *)parseDatatoJsonData :(NSMutableDictionary *)data;
/*!
    @function URLEncodedString
    @brief Encode the string of url into URL friendly form
    @param urlString The string that wants to be encodded
    @return URL friendly NSString
 */
- (NSString *)URLEncodedString :(NSString *)urlString;
/*!
    @function URLDecodedString
    @brief Decode the string of url into normal NSString
    @param urlString The string that wants to be decoded
    @return normal NSString
 */
- (NSString *)URLDecodedString :(NSString *)urlString;
/*!
    @function dictionaryWithQueryString
    @brief Parse the queryString from format http://example.com?key1=value1&key2=value2 into NSdictionary
    @param urlString The string that wants to be parsed
    @return NSDictionary containing the pair values
 */
- (NSDictionary *)dictionaryWithQueryString: (NSString *)queryString;

/*!
 @function lrSaveUserData
 @brief Get the LoginRadius user profile data and saved them into NSUserDefault
 @param userProfile Pass in the profile directly, usually from Traditional Login
 @param token LoginRadius access token, call lrGetUserProfile function to get the user data
 @seealso LoginRadiusUserRegistration.h
 @return NSDictionary containing the pair values
 */
- (BOOL)lrSaveUserData :(NSMutableDictionary *)userProfile lrToken:(NSString *)token;


@end

@interface NSMutableDictionary (LoginRadius)
/*!
 @function replaceNullWithBlank
 @brief Extend NSMutableDictionary, replace self <null> values with blank string @""
 @return self
 */
- (NSMutableDictionary *) replaceNullWithBlank;

@end