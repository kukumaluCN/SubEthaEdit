//
//  TCMMMBEEPSessionManager.h
//  SubEthaEdit
//
//  Created by Dominik Wagner on Fri Feb 27 2004.
//  Copyright (c) 2004 TheCodingMonkeys. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const ProhibitInboundInternetSessions;

extern NSString * const TCMMMBEEPSessionManagerDidAcceptSessionNotification;
extern NSString * const TCMMMBEEPSessionManagerSessionDidEndNotification;
extern NSString * const TCMMMBEEPSessionManagerConnectToHostDidFailNotification;
extern NSString * const TCMMMBEEPSessionManagerConnectToHostCancelledNotification;

@class TCMBEEPListener, TCMHost, TCMBEEPSession;

@interface TCMMMBEEPSessionManager : NSObject
{
    TCMBEEPListener *I_listener;
    int I_listeningPort;
    NSMutableDictionary *I_sessionInformationByUserID;
    NSMutableSet *I_pendingSessions;
    NSMutableSet *I_pendingSessionProfiles;
    NSMutableArray *I_sessions;
    
    NSMutableDictionary *I_outboundInternetSessions;
    BOOL I_isProhibitingInboundInternetSessions;
}

+ (TCMMMBEEPSessionManager *)sharedInstance;
- (BOOL)listen;
- (int)listeningPort;

- (void)setIsProhibitingInboundInternetSessions:(BOOL)flag;
- (BOOL)isProhibitingInboundInternetSessions;

- (void)connectToNetService:(NSNetService *)aNetService;
- (void)connectToHost:(TCMHost *)aHost;
- (void)cancelConnectToHost:(TCMHost *)aHost;

- (TCMBEEPSession *)sessionForUserID:(NSString *)aUserID;

@end
