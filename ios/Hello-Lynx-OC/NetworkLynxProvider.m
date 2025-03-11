#import <Foundation/Foundation.h>

#import "NetworkLynxProvider.h"

@implementation NetworkLynxProvider

- (void)loadTemplateWithUrl:(NSString*)url onComplete:(LynxTemplateLoadBlock)callback {
    NSURL* nsUrl = [NSURL URLWithString:url];
    NSURLSessionDataTask* task = [[NSURLSession sharedSession]
        dataTaskWithURL:nsUrl
        completionHandler:^(NSData* _Nullable data, NSURLResponse* _Nullable response,
                            NSError* _Nullable error) {
          dispatch_async(dispatch_get_main_queue(), ^{
            if (error) {
              callback(data, error);
            } else if (!data) {
              NSMutableDictionary* details = [NSMutableDictionary new];
              NSString* errorMsg = [NSString stringWithFormat:@"data from %@ is nil!", url];
              [details setObject:errorMsg forKey:NSLocalizedDescriptionKey];
              NSError* data_error = [NSError errorWithDomain:@"com.lynx" code:200 userInfo:details];
              callback(nil, data_error);
            } else {
              callback(data, nil);
            }
          });
        }];
    [task resume];
}

@end
