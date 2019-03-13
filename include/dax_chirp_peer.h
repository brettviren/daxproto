/*  =========================================================================
    dax_chirp_peer - DAX Chirp peer

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: dax_chirp_peer.xml, or
     * The code generation script that built this file: zproto_zyrepeer_c
    ************************************************************************
    =========================================================================
*/

#ifndef DAX_CHIRP_PEER_H_INCLUDED
#define DAX_CHIRP_PEER_H_INCLUDED

#include <czmq.h>

#include <zyre.h>

#ifdef __cplusplus
extern "C" {
#endif

//  Opaque class structure
#ifndef DAX_CHIRP_PEER_T_DEFINED
typedef struct _dax_chirp_peer_t dax_chirp_peer_t;
#define DAX_CHIRP_PEER_T_DEFINED
#endif

//  @interface
//  Create a new dax_chirp_peer, return the reference if successful, or NULL
//  if construction failed due to lack of available memory.
dax_chirp_peer_t *
    dax_chirp_peer_new (void);

//  Destroy the dax_chirp_peer and free all memory used by the object.
void
    dax_chirp_peer_destroy (dax_chirp_peer_t **self_p);

//  Return actor, when caller wants to work with multiple actors and/or
//  input sockets asynchronously.
zactor_t *
    dax_chirp_peer_actor (dax_chirp_peer_t *self);

//  Return message pipe for asynchronous message I/O. In the high-volume case,
//  we send methods and get replies to the actor, in a synchronous manner, and
//  we send/recv high volume message data to a second pipe, the msgpipe. In
//  the low-volume case we can do everything over the actor pipe, if traffic
//  is never ambiguous.
zsock_t *
    dax_chirp_peer_msgpipe (dax_chirp_peer_t *self);

//  Return true if client is currently connected, else false. Note that the
//  client will automatically re-connect if the server dies and restarts after
//  a successful first connection.
bool
    dax_chirp_peer_connected (dax_chirp_peer_t *self);

//  Enable verbose tracing (animation) of state machine activity.
void
    dax_chirp_peer_set_verbose (dax_chirp_peer_t *self, bool verbose);

//  Self test of this class
void
    dax_chirp_peer_test (bool verbose);
//  @end

#ifdef __cplusplus
}
#endif

#endif