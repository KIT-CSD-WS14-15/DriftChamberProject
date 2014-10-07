#pragma once

#include <map>
#include <string>

enum class Durability {event, persistent};

template <class Storable>
class DataStore{
public:
  DataStore& Instance(){
	  static DataStore instance;
	  return instance;
  }

  Storable& getStorable(std::string name, Durability durability = Durability::event){
	  if (durability == Durability::event){
		  return m_eventMap[name];
	  }

	  return m_persistentMap[name];
  }

  void store(std::string name, Storable* Astorable, Durability durability = Durability::event){
    if (durability == Durability::event){
    	m_eventMap[name] = Astorable;
    } else {
    	m_persistentMap[name] = Astorable;
    }
  }

  DataStore& operator=(const DataStore&) = delete;

  DataStore (const DataStore&) = delete;

private:

  explicit DataStore() {};

  std::map<std::string, Storable> m_persistentMap;

  std::map<std::string, Storable> m_eventMap;
};
