/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsWifiEvent.h"

#define WIFIEVENT_CID                                \
  {                                                  \
    0x93c570c2, 0x1ece, 0x44f2, {                    \
      0x9a, 0xa5, 0x34, 0xc2, 0xcd, 0xca, 0xde, 0x40 \
    }                                                \
  }

/**
 * nsWifiEvent
 */
NS_IMPL_ISUPPORTS(nsWifiEvent, nsIWifiEvent)

nsWifiEvent::nsWifiEvent() {}

nsWifiEvent::nsWifiEvent(const nsAString& aName) { mName = aName; }

void nsWifiEvent::updateStateChanged(nsStateChanged* aStateChanged) {
  mStateChanged = aStateChanged;
}

NS_IMETHODIMP
nsWifiEvent::GetName(nsAString& aName) {
  aName = mName;
  return NS_OK;
}

NS_IMETHODIMP
nsWifiEvent::GetBssid(nsAString& aBssid) {
  aBssid = mBssid;
  return NS_OK;
}

NS_IMETHODIMP
nsWifiEvent::GetLocallyGenerated(bool* aLocallyGenerated) {
  *aLocallyGenerated = mLocallyGenerated;
  return NS_OK;
}

NS_IMETHODIMP
nsWifiEvent::GetReason(uint32_t* aReason) {
  *aReason = mReason;
  return NS_OK;
}

NS_IMETHODIMP
nsWifiEvent::GetNumStations(uint32_t* aNumStations) {
  *aNumStations = mNumStations;
  return NS_OK;
}

NS_IMETHODIMP
nsWifiEvent::GetStateChanged(nsIStateChanged** aStateChanged) {
  RefPtr<nsIStateChanged> stateChanged(mStateChanged);
  stateChanged.forget(aStateChanged);
  return NS_OK;
}

NS_DEFINE_NAMED_CID(WIFIEVENT_CID);
