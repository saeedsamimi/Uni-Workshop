//
// Created by Saeed Samimi on 5/22/2024.
//

#ifndef POSTSERVICE_PACKAGE_H
#define POSTSERVICE_PACKAGE_H

#include <string>

using std::string;

class Package {
private:
  string m_first_name;
  
  string m_last_name;
  
  string m_address;
  
  string m_city;
  
  string m_united;
  
  string m_sender_post;
  
  string m_receiver_post;
  
  int m_weight;
  
  double m_price_per_once;

public:
  Package();
  Package(string name,
          string lastName,
          string address,
          string city,
          string united,
          string sender_post,
          string receiverPost,
          int weight);
  [[nodiscard]] const string &getFirstName() const;
  void setFirstName(const string &mFirstName);
  [[nodiscard]] const string &getLastName() const;
  void setLastName(const string &mLastName);
  [[nodiscard]] const string &getAddress() const;
  void setAddress(const string &mAddress);
  [[nodiscard]] const string &getCity() const;
  void setCity(const string &mCity);
  [[nodiscard]] const string &getUnited() const;
  void setUnited(const string &mUnited);
  [[nodiscard]] const string &getSenderPost() const;
  void setSenderPost(const string &mSenderPost);
  [[nodiscard]] const string &getReceiverPost() const;
  void setReceiverPost(const string &mReceiverPost);
  [[nodiscard]] int getWeight() const;
  void setWeight(int mWeight);
  [[nodiscard]] double getPricePerOnce() const;
  void setPricePerOnce(double mPricePerOnce);
  virtual double calculateCost() const;
};


#endif //POSTSERVICE_PACKAGE_H
