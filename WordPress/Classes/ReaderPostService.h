#import <Foundation/Foundation.h>
#import "LocalService.h"

@class ReaderPost;
@class ReaderTopic;

@interface ReaderPostService : NSObject<LocalService>

/**
 Fetches the posts for the specified topic

 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)fetchPostsForTopic:(ReaderTopic *)topic
                   success:(void (^)(NSUInteger count))success
                   failure:(void (^)(NSError *error))failure;

/**
 Fetches the posts for the specified topic

 @param date The date to get posts earlier than.
 @param keepExisting YES if existing posts should kept, otherwise they are deleted in favor of the newest content.
 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)fetchPostsForTopic:(ReaderTopic *)topic
               earlierThan:(NSDate *)date
              keepExisting:(BOOL)keepExisting
                   success:(void (^)(NSUInteger count))success
                   failure:(void (^)(NSError *error))failure;

/**
 Fetches a specific post from the specified remote site

 @param postID The ID of the post to fetch.
 @param siteID The ID of the post's site.
 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)fetchPost:(NSUInteger)postID
          forSite:(NSUInteger)siteID
          success:(void (^)(ReaderPost *post))success
          failure:(void (^)(NSError *error))failure;


/**
 Toggle the liked status of the specified post.

 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)toggleLikedForPost:(ReaderPost *)post
                   success:(void (^)())success
                   failure:(void (^)(NSError *error))failure;

/**
 Toggle the following status of the specified post's blog.

 @param post The ReaderPost whose blog should be followed.
 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)toggleFollowingForPost:(ReaderPost *)post
                       success:(void (^)())success
                       failure:(void (^)(NSError *error))failure;

/**
 Reblog the specified post to a target blog. Optionally including a note.

 @param post The ReaderPost to reblog.
 @param siteID The ID of the destination site.
 @param note (Optional.) A short note about the reblog.
 @param success block called on a successful fetch.
 @param failure block called if there is any error. `error` can be any underlying network error.
 */
- (void)reblogPost:(ReaderPost *)post
            toSite:(NSUInteger)siteID
              note:(NSString *)note
           success:(void (^)())success
           failure:(void (^)(NSError *error))failure;

@end
