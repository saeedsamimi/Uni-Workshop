//
// Created by Saeed Samimi on 5/22/2024.
//

#include "package.h"
#include <cmath>

#define MV(x) std::move(x)

Package::Package(string name,
                 string lastName,
                 string address,
                 string city,
                 string united,
                 string sender_post,
                 string receiverPost, int weight) :
        m_first_name(MV(name)), m_last_name(MV(lastName)), m_address(MV(address)),
        m_city(MV(city)), m_united(MV(united)), m_sender_post(MV(sender_post)),
        m_receiver_post(MV(receiverPost)),
        m_weight(weight > 0 ? weight : 0),
        m_price_per_once(27.5) {}

Package::Package() :
        Package("", "", "", "", "", "+0", "+0", 0) {}

const string &Package::getFirstName() const {
  return m_first_name;
}

void Package::setFirstName(const string &mFirstName) {
  m_first_name = mFirstName;
}

const string &Package::getLastName() const {
  return m_last_name;
}

void Package::setLastName(const string &mLastName) {
  m_last_name = mLastName;
}

const string &Package::getAddress() const {
  return m_address;
}

void Package::setAddress(const string &mAddress) {
  m_address = mAddress;
}

const string &Package::getCity() const {
  return m_city;
}

void Package::setCity(const string &mCity) {
  m_city = mCity;
}

const string &Package::getUnited() const {
  return m_united;
}

void Package::setUnited(const string &mUnited) {
  m_united = mUnited;
}

const string &Package::getSenderPost() const {
  return m_sender_post;
}

void Package::setSenderPost(const string &mSenderPost) {
  m_sender_post = mSenderPost;
}

const string &Package::getReceiverPost() const {
  return m_receiver_post;
}

void Package::setReceiverPost(const string &mReceiverPost) {
  m_receiver_post = mReceiverPost;
}

int Package::getWeight() const {
  return m_weight;
}

void Package::setWeight(int mWeight) {
  m_weight = std::max(0, mWeight);
}

double Package::getPricePerOnce() const {
  return m_price_per_once;
}

void Package::setPricePerOnce(double mPricePerOnce) {
  m_price_per_once = std::max(0., mPricePerOnce);
}

double Package::calculateCost() const {
  return m_weight * m_price_per_once;
}

#undef MV
