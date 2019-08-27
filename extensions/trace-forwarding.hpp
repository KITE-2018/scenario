/* -*-  Mode: C++; c-file-style: "gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2019 Harbin Institute of Technology, China
 *
 * Author: Zhongda Xia <xiazhongda@hit.edu.cn>
 **/

#ifndef NDN_KITE_TRACE_FORWARDING_STRATEGY_HPP
#define NDN_KITE_TRACE_FORWARDING_STRATEGY_HPP

#include "face/face.hpp"
#include "fw/strategy.hpp"
#include "fw/algorithm.hpp"

namespace nfd {
namespace fw {

class TraceForwardingStrategy : public Strategy {
public:
  explicit
  TraceForwardingStrategy(Forwarder& forwarder, const Name& name = getStrategyName());

  static const Name&
  getStrategyName();

  void
  afterReceiveInterest(const Face& inFace, const Interest& interest,
                       const shared_ptr<pit::Entry>& pitEntry) override;

  void
  afterReceiveNack(const Face& inFace, const lp::Nack& nack,
                   const shared_ptr<pit::Entry>& pitEntry) override;

  bool
  TraceForwarding(const Face& inFace, const Interest& interest,
                  const shared_ptr<pit::Entry>& pitEntry, const tib::Entry& tibEntry);

public:
  static const Name STRATEGY_NAME;
};

} // namespace fw
} // namespace nfd

#endif // NDN_KITE_TRACE_FORWARDING_STRATEGY_HPP