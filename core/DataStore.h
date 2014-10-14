#pragma once

#include <map>
#include <string>
#include <memory>

/** A Singleton for communication of objects across modules.
 *
 *  Use the Instance function to access the Singleton.
 *  For each class of objects communicated a separate DataStore will
 *  be instantiated.
 *  The DataStore consists basically of a map with std::string as key
 *  and one of the transfered objects as mapped.
 *
 *  http://de.wikipedia.org/wiki/Singleton_(Entwurfsmuster)
 */
template <class Storable>
class DataStore {
public:
  /** This is the function to actually access the Singleton. */
  static DataStore<Storable>& Instance() {
    static DataStore<Storable> instance;
    return instance;
  }

  /** Get a specific object from the Singleton.
   *
   *  If you have several objects of the same type, you can store them
   *  all. You have to give a name as key for the map of objects.
   */
  std::shared_ptr<Storable> getStorable(std::string name) {
    return m_storableMap[name];
  }

  /** Store an object of type Storable.
   *
   *  The recommendation is to use as name the class name,
   *  if you want to store just one object of the given type.
   *  If you have several objects, you will typically have a reason for that,
   *  that can be reflected in the name.
   */
  void store(std::string name, std::shared_ptr<Storable> AstorablePtr) {
    m_storableMap[name] = AstorablePtr;
  }

  /** Getting rid of assignment operator, as this is a Singleton. */
  DataStore<Storable>& operator=(const DataStore<Storable>&) = delete;

  /** Getting rid of assignment constructor, as this is a Singleton. */
  DataStore<Storable> (const DataStore<Storable>&) = delete;

private:
  explicit DataStore<Storable>()
  {};

  std::map<std::string, std::shared_ptr<Storable> > m_storableMap;
};
