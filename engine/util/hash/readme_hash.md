## Hash Library ##

Strings can be big performance bottlenecks in engines and are relatively simple to avoid when designing a system but really hard to replace after the fact

Enums can be used in many places, but a really cool workaround is hashing the strings for all operations using a consistent hash function such as [MD5](https://en.wikipedia.org/wiki/MD5). How it works is that outer functions in our API take strings as input, but are immediately hashed internally (transformed into an integer) for storage/searching.

for example
```		
	// --> game.cpp 	
    TextureManager::LoadResource("brickWall", "resources/bricks.png");

    // --> texturemanager.cpp 
    void TextureManager::LoadResource(const char* key, const char* path)
    {
	  int id = MD5::FromString(key);
	  uchar8* data;
	  // load from path into data somehow...
	  // add to dictionary using id rather than the string 
	  this->_textures.add(/*key: */ id, /*value: */data);   
    }
```

We will need an MD5 library to do this (or use a different hash function, but we can probably find an MD5 lib easy and it's worked for me before)

