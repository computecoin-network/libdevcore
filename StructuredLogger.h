/*
	This file is part of cpp-ethereum.

	cpp-ethereum is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	cpp-ethereum is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with cpp-ethereum.  If not, see <http://www.gnu.org/licenses/>.
*/
/** @file StructuredLogger.h
 * @author Lefteris Karapetsas <lefteris@ethdev.com>
 * @date 2015
 *
 * A simple helper class for the structured logging
 */

#pragma once

#include <string>
#include <chrono>
#include <libp2p/Network.h>

namespace Json { class Value; }

namespace dev
{

class StructuredLogger
{
public:
	StructuredLogger(bool _enabled): m_enabled(_enabled) {}

	void logStarting(std::string const& _clientImpl, const char* _ethVersion);
	void logP2PConnected(std::string const& _id, bi::tcp::endpoint const& _addr,
		std::chrono::system_clock::time_point const& _ts, unsigned int _numConnections) const;
	void logP2PDisconnected(std::string const& _id, unsigned int _numConnections, bi::tcp::endpoint const& _addr) const;
	void logMinedNewBlock(std::string const& _hash, std::string const& _blockNumber,
		  std::string const& _chainHeadHash, std::string const& _prevHash) const;
	void logChainReceivedNewBlock(std::string const& _hash, std::string const& _blockNumber, std::string const& _chainHeadHash,
		  std::string const& _remoteID, std::string const& _prevHash) const;
	void logChainNewHead(std::string const& _hash, std::string const& _blockNumber, std::string const& _chainHeadHash,
		  std::string const& _prevHash) const;
	void logTransactionReceived(std::string const& _hash, std::string const& _remoteId) const;
private:
	/// @returns a string representation of a timepoint
	char const* timePointToString(std::chrono::system_clock::time_point const& _ts) const;
	void outputJson(Json::Value const* _value, std::string const& _name) const;
	bool m_enabled;

};

}
