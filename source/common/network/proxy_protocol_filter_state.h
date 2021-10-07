#pragma once

#include "envoy/network/proxy_protocol.h"
#include "envoy/stream_info/filter_state.h"

namespace Envoy {
namespace Network {

/**
 * PROXY protocol info to be used in connections.
 */
class ProxyProtocolFilterState : public StreamInfo::FilterState::Object {
public:
  ProxyProtocolFilterState(Network::ProxyProtocolData options) : options_(options) {}
  Network::ProxyProtocolData& value() { return options_; }
  static const std::string& key();

private:
  Network::ProxyProtocolData options_;
};

} // namespace Network
} // namespace Envoy
