//
// Copyright (c) 2013-2017 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef BEAST_HTTP_ERROR_HPP
#define BEAST_HTTP_ERROR_HPP

#include <beast/config.hpp>
#include <beast/core/error.hpp>

namespace beast {
namespace http {

/// Error codes returned from HTTP algorithms and operations.
enum class error
{
    /** The end of the stream was reached.

        This error is returned under the following conditions:

        @li When attempting to read HTTP data from a stream and the stream
        read returns the error `boost::asio::error::eof` before any new octets
        have been received.

        @li When sending a complete HTTP message at once and the semantics of
        the message are that the connection should be closed to indicate the
        end of the message.
    */
    end_of_stream = 1,

    /** The incoming message is incomplete.

        This happens when the end of stream is reached during
        parsing and some octets have been received, but not the
        entire message.
    */
    partial_message,

    /** Additional buffers are required.

        This error is returned during parsing when additional
        octets are needed. The caller should append more data
        to the existing buffer and retry the parse operaetion.
    */
    need_more,

    /** An unexpected body was encountered during parsing.

        This error is returned when attempting to parse body
        octets into a message container which has the
        @ref empty_body body type.

        @see @ref empty_body
    */
    unexpected_body,

    /** Additional buffers are required.

        This error is returned under the following conditions:

        @li During serialization when using @ref buffer_body.
        The caller should update the body to point to a new
        buffer or indicate that there are no more octets in
        the body.

        @li During parsing when using @ref buffer_body.
        The caller should update the body to point to a new
        storage area to receive additional body octets.
    */
    need_buffer,

    /** Buffer maximum exceeded.

        This error is returned when reading HTTP content
        into a dynamic buffer, and the operation would
        exceed the maximum size of the buffer.
    */
    buffer_overflow,

    //
    // (parser errors)
    //

    /// The line ending was malformed
    bad_line_ending,

    /// The method is invalid.
    bad_method,

    /// The request-target is invalid.
    bad_path,

    /// The HTTP-version is invalid.
    bad_version,

    /// The status-code is invalid.
    bad_status,

    /// The reason-phrase is invalid.
    bad_reason,

    /// The field name is invalid.
    bad_field,

    /// The field value is invalid.
    bad_value,

    /// The Content-Length is invalid.
    bad_content_length,

    /// The Transfer-Encoding is invalid.
    bad_transfer_encoding,

    /// The chunk syntax is invalid.
    bad_chunk,

    /// An obs-fold exceeded an internal limit.
    bad_obs_fold
};

} // http
} // beast

#include <beast/http/impl/error.ipp>

#endif
