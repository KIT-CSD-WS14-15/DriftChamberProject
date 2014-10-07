#pragma once

#include <map>
#include <string>
#include <memory>

enum class Durability {event, persistent};

template <class Storable>
class DataStore{
public:
  static DataStore<Storable>& Instance(){
	  static DataStore<Storable> instance;
	  return instance;
  }

  std::shared_ptr<Storable> getStorable(std::string name, Durability durability = Durability::event){
	  if (durability == Durability::event){
		  return m_eventMap[name];
	  }

	  return m_persistentMap[name];
  }

  void store(std::string name, std::shared_ptr<Storable> AstorablePtr, Durability durability = Durability::event){
    if (durability == Durability::event){
    	m_eventMap[name] = AstorablePtr;
    } else {
    	m_persistentMap[name] = AstorablePtr;
    }
  }

  DataStore<Storable>& operator=(const DataStore<Storable>&) = delete;

  DataStore<Storable> (const DataStore<Storable>&) = delete;

private:
  explicit DataStore<Storable>()
  {};

  std::map<std::string, std::shared_ptr<Storable> > m_persistentMap;

  std::map<std::string, std::shared_ptr<Storable> > m_eventMap;
};
