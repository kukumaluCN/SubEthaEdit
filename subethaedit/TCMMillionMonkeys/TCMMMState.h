//
//  TCMMMState.h
//  SubEthaEdit
//
//  Created by Martin Ott on Fri Mar 19 2004.
//  Copyright (c) 2004 TheCodingMonkeys. All rights reserved.
//

#import <Foundation/Foundation.h>


@class TCMMMState, TCMMMMessage, TCMMMOperation;


@protocol TCMMMStateClientProtocol

- (void)state:(TCMMMState *)aState handleMessage:(TCMMMMessage *)aMessage;

@end


@interface TCMMMState : NSObject {
    long long I_numberOfClientMessages;
    long long I_numberOfServerMessages;
    NSMutableArray *I_messageBuffer;
    BOOL I_isServer;
    NSObject <TCMMMStateClientProtocol> *I_client;
    id I_delegate;
}

- (id)initAsServer:(BOOL)isServer;

- (BOOL)isServer;
- (void)setClient:(NSObject <TCMMMStateClientProtocol> *)aClient;
- (NSObject <TCMMMStateClientProtocol> *)client;
- (void)setDelegate:(id)aDelegate;
- (id)delegate;

- (void)handleMessage:(TCMMMMessage *)aMessage;
- (void)handleOperation:(TCMMMOperation *)anOperation;

@end


@interface NSObject (TCMMMStateDelegateAdditions)

- (void)state:(TCMMMState *)aState handleOperation:(TCMMMOperation *)anOperation;

@end

/*
[session documentDidApplyOperation:];
[state handleOperation:];
[client state:self handleMessage:];


[state    handleMessage:]
[delegate state:self handleOperation:]
[document handleOperation:]
*/


