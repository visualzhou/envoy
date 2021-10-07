#pragma once

#include "envoy/network/address.h"

#include <vector>

namespace Envoy {
namespace Network {

struct ProxyProtocolTLV {
  uint8_t type;
  std::string key;
  std::string value;
};

struct ProxyProtocolData {
  const Network::Address::InstanceConstSharedPtr src_addr_;
  const Network::Address::InstanceConstSharedPtr dst_addr_;
  std::vector<ProxyProtocolTLV> tlv_vector_ = {};
  std::string asStringForHash() const {
    return std::string(src_addr_ ? src_addr_->asString() : "null") +
           (dst_addr_ ? dst_addr_->asString() : "null");
  }
};

} // namespace Network
} // namespace Envoy
