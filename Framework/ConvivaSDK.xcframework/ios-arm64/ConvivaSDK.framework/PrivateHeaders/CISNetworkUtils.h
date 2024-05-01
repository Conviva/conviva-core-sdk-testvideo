//
//  CISNetworkUtils.h
//  Pods
//
//  Created by Sandeep Madineni on 18/06/20.
//

#import <Foundation/Foundation.h>
#import <Network/Network.h>
#import "CISLogger.h"

NS_ASSUME_NONNULL_BEGIN

typedef enum {
    CISNetworkTypeNotConnected = 0,
    CISNetworkTypeWWAN = 1,
    CISNetworkTypeWiFi = 2,
    CISNetworkTypeEthernet = 3
} CISNetworkType;

@interface CISNetworkUtils : NSObject {
    BOOL isMonitoring;
}

@property (atomic, copy) void (^netStatusChangeHandler)(void);

@property (nonatomic, strong) nw_path_monitor_t monitor;

@property (nonatomic, strong) nw_path_t currentPath;

@property (nonatomic, strong) CISLogger *cisLogger;

+(CISNetworkUtils *)sharedInstance;
-(void)startMonioring API_AVAILABLE(ios(12), tvos(12));
-(void)stopMonitoring API_AVAILABLE(ios(12), tvos(12));
-(BOOL)isConnectedToWifiOrEthernet API_AVAILABLE(ios(12), tvos(12));
-(CISNetworkType)currentNetworkType API_AVAILABLE(ios(12), tvos(12));

- (void)assignLogger:(CISLogger *)logger;

@end

NS_ASSUME_NONNULL_END
