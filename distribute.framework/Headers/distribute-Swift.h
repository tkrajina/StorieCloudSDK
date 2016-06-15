// Generated by Apple Swift version 2.2 (swiftlang-703.0.18.8 clang-703.0.31)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class NSURL;
@protocol DistributorDelegate;


/// Distributor is the main interface needed to interact with the Storie Developer API. It's primary purpose is to create video objects, coordinate resumable background uploads and report back various events.
SWIFT_CLASS("_TtC10distribute11Distributor")
@interface Distributor : NSObject

/// Construct the Distributor object with the API key supplied in the Storie Developer Console. Be sure to obfuscate this key.
///
/// \param apiKey The apiKey
- (nullable instancetype)initWithApiKey:(NSString * _Nonnull)apiKey error:(NSError * _Nullable * _Null_unspecified)error OBJC_DESIGNATED_INITIALIZER;

/// Delegate that provides callback functionality about upload statuses
@property (nonatomic, weak) id <DistributorDelegate> _Nullable delegate;

/// Number of uploads currently in the upload queue
@property (nonatomic, readonly) NSInteger queueCount;

/// Returns a dictionary of objectIDs to userInfo of uploads that have not completely uploaded
@property (nonatomic, readonly, copy) NSDictionary<NSString *, NSDictionary<NSString *, id> *> * _Nonnull queue;

/// A property indicating whether uploads are currently suspended or running
///
/// This property does not indicate if there is an active upload in the queue or not.
/// The state of this property is not persisted between application loads and it's default value is always initialized to <code>true
/// </code>.
@property (nonatomic, readonly) BOOL uploadsSuspended;

/// Calling this method will ensure all stopped and pending uploads get initialized and start uploading.
- (void)initializeUploads;

/// If uploadsSuspended returns false, calling this method will cause any pending uploads to resume.
- (void)resumeUploads;

/// If uploadsSuspended returns true, calling this method will cause any active uploads to be suspended.
- (void)suspendUploads;

/// Suspends the upload
///
/// \param objectID the <code>id
/// </code> of the upload object, this assigned to the object when the upload is initialized
- (void)suspend:(NSString * _Nonnull)objectID;

/// Resumes the upload
///
/// \param objectID the <code>id
/// </code> of the upload object, this assigned to the object when the upload is initialized
- (void)resume:(NSString * _Nonnull)objectID;

/// Cancels the upload
///
/// \param objectID the <code>id
/// </code> of the upload object, this assigned to the object when the upload is initialized
- (void)cancel:(NSString * _Nonnull)objectID;

/// Cancels all uploads
- (void)cancelAll;

/// Hands over the completionHandler and sessionIdentifier identifier used by the internal background URL session that are provided by the UIApplicationDelegate function application(_:handleEventsForBackgroundURLSession:completionHandler:)
///
/// See: https://developer.apple.com/library/ios/documentation/UIKit/Reference/UIApplicationDelegate_Protocol/#//apple_ref/occ/intfm/UIApplicationDelegate/application:handleEventsForBackgroundURLSession:completionHandler:
///
/// \param sessionIdentifier string provided in <code>application(_:handleEventsForBackgroundURLSession:completionHandler:)
/// </code>
///
/// \param completionHandler closure provided in <code>application(_:handleEventsForBackgroundURLSession:completionHandler:)
/// </code>
- (void)handleEventsForBackgroundSession:(NSString * _Nonnull)sessionIdentifier completionHandler:(void (^ _Nullable)(void))completionHandler;

/// Instructs the SDK to create and start uploading a file to the Storie API. mp4 and mov file types are supported for now.
///
/// \param fileURL the location on local disk of the file you would like to upload
///
/// \param userInfo passthrough dictionary, provided back via <code>DistributorDelegate
/// </code> functions and in <code>UploadNotifications
/// </code>. This data is serialized to JSON and stored in local storage. Only objects that conform to the rules of serializing data for the <code>NSJSONSerialization
/// </code> class will be accepted. For more info: https://developer.apple.com/library/ios/documentation/Foundation/Reference/NSJSONSerialization_Class/#//apple_ref/occ/clm/NSJSONSerialization/dataWithJSONObject:options:error:
///
/// \param callbackData any information you would like to have passed with your <code>callbackURL
/// </code> when processing of your file has completed. This data is provided to your callback endpoint as a <code>JSON
/// </code> map of <code>[String : String]
/// </code> types.
///
/// \param processingProfile the name of the processing profile in the Storie Developer Console you are using to process this file. If <code>nil
/// </code> the default proessing profile will be used.
///
/// \param thumbnailTime Override the default thumbnail time in the profile, leave nil if you want generation of thumbnails to be specified by the profile. Note: if the time is invalid e.g. greater than the duration of the video, the default thumbnail time specified in the profile will be used.
///
/// \param error <code>UploadError.InvalidFilePath
/// </code> if the <code>fileURL
/// </code> parameter points to an invalid file path or the file does not exist
- (BOOL)upload:(NSURL * _Nonnull)fileURL userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo callbackData:(NSDictionary<NSString *, NSString *> * _Nullable)callbackData pipelineName:(NSString * _Nullable)pipelineName thumbnailTime:(NSTimeInterval)thumbnailTime error:(NSError * _Nullable * _Null_unspecified)error;

/// Objective-C Compatible function that retrieves the object's metadata, if using Swift rather use: videoInfo(videoID: String, success: Video -> Void) throws
///
/// \param videoID Unique identifier for the video object
///
/// \param success Success callback that contains <code>NSDictionary
/// </code> of values
///
/// \param error An error is thrown if retrieving the video info has failed
- (BOOL)videoInfo:(NSString * _Nonnull)videoID error:(NSError * _Nullable * _Null_unspecified)error success:(void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull))success;
@end

@class NSProgress;
@class NSError;
@class UploadCompleteResult;


/// Types adopting the DistributorDelegate protocol and assigned to the Distributor object's delegate will receive feedback about various events in the upload lifecycle.
SWIFT_PROTOCOL("_TtP10distribute19DistributorDelegate_")
@protocol DistributorDelegate
@optional

/// The upload has been registered with the Storie API and is now able to start uploading
///
/// \param objectID a unique ID identifying the upload object. This can be used to query the status of a video object using the function <code>getVideo(videoID: String)
/// </code>.
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
- (void)uploadDidInitialize:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo;

/// A new upload has started - this is different to uploadDidResume in that it is only ever called when a new upload has started uploading.
///
/// \param objectID a unique ID identifying the upload object.
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
- (void)uploadDidStart:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo;

/// An upload has resumed - if an upload was interrupted and is now resuming this function will be called.
///
/// \param objectID a unique ID identifying the upload object.
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
- (void)uploadDidResume:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo;

/// Upload progress is reported on this callback, this is the global progress of all active uploads.
///
/// \param objectID identifies the upload that has progressed
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
///
/// \param progress indicates progress of specified upload
///
/// \param totalProgress indicates total progress of all uploads
- (void)uploadDidProgress:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo progress:(NSProgress * _Nonnull)progress totalProgress:(NSProgress * _Nonnull)totalProgress;

/// An upload has completed successfully
///
/// \param objectID a unique ID identifying the upload object.
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
- (void)uploadDidFinish:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo;

/// An upload has failed
///
/// \param objectID a unique ID identifying the upload object.
///
/// \param userInfo passthrough dictionary provided in the function <code>upload(_:userInfo:callbackData:processingProfile:)
/// </code>
///
/// \param error the underlying reason why the upload has failed.
- (void)uploadDidFail:(NSString * _Nonnull)objectID userInfo:(NSDictionary<NSString *, id> * _Nullable)userInfo withError:(NSError * _Nullable)error;

/// When all current uploads have finished uploading and there are no pending uploads remaining.
- (void)uploadsCompleted:(NSArray<UploadCompleteResult *> * _Nonnull)results;
@end


@interface NSDate (SWIFT_EXTENSION(distribute))
@end


@interface NSDate (SWIFT_EXTENSION(distribute))
@end


@interface NSURL (SWIFT_EXTENSION(distribute))
@end

enum UploadResultConstant : NSInteger;


/// Indicates the state in which uploads had been completed
SWIFT_CLASS("_TtC10distribute20UploadCompleteResult")
@interface UploadCompleteResult : NSObject

/// Indication of the result constant
@property (nonatomic, readonly) enum UploadResultConstant result;

/// If result is .Failed then inspect this property for the associated error
@property (nonatomic, readonly, strong) NSError * _Nullable error;

/// The unique ID given to this upload on the Storie API
@property (nonatomic, readonly, copy) NSString * _Nonnull objectID;

/// Passthrough data provided in the upload function. See Distributor for more info.
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id> * _Nullable userInfo;
@end


/// Enum representing the actual result status.
typedef SWIFT_ENUM(NSInteger, UploadResultConstant) {

/// The upload completed successfully
  UploadResultConstantSuccess = 0,

/// The upload failed
  UploadResultConstantFailed = 1,

/// The upload was cancelled by the user
  UploadResultConstantCancelled = 2,
};

#pragma clang diagnostic pop
