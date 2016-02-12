
#include <stdio.h>

// way Xanny used to work is a collection of texts, where you can pull documents. this is more of an encyclopaedia
// than a collection of primary sources.
// so what do I do with primary sources...

// I'm inevitably creating a hiearchy here... the units are letters, words, punctuation, but the letter and
// punctuation are unique because things are made up of them, dog, cat-dog. So let's build up a system of
// represeting language: an alphabet, where each symbol is an entry, but larger entries are composed of them,
// how do I prevent letters from being a special case (or are they?)
// they have an id, okay, but no name? and how can Text be a collection of text? everything is endlessly circular
// because if you have an entry for A, you define it with a series of words which are only represented by it.
// and where do links fit in? and if there's a distinction between a document and some text (which really there
// shouldnt be, it's just streams of characters) then the document is made up of text.
// I guess I just want arbitrary data mapped to each char in a range.

// A dictionary may be the way to go, and just treat letters as primary symbols which Xanny can't necessarily
// explain outside of her system (Godel). The problem with the dictionary is it's still circular. Maybe it is
// better to just let the player create the links, but Xanny should make it clear that that's how you should put
// her to use. There have to be links between the words and their dictionary entry at the very least, and player
// can do more with it from there. 


// Does the order of links matter when creating them, like pointing O P E N towards the door.

// Let's take the alphabet:
// A: first letter
// B: second letter
// C: third letter
// ...
// Z: last letter

// so this is text "A" and it's mapped to a series of texts, where each letter is an inspectable text, but so are
// ranges of them...

// is this a hypergraph... collections of nodes, but aren't some nodes made up out of others? they're a coloring
// of primary set, but with a defined order... a link exists within a certain coloring.
// but how is something like "abba cadabra" formed? most node appears appear several times...
// can a coloring contain repeats of a node (does that even make sense.)
// "a hypergraph is then just a collection of trees with common shared node, that is a given internal node or leaf
// may occur in several different trees", but its a directed acyclic graph which seems unsuited for this...


// I still don't like this because a letter is just a minimum-sized word really, but I guess A is different from a
// but just in definition right, but one seems to have primacy, you can't have the article without the letter.


// Does this include punctuation? whitespace?
struct Alpha {
  char Upper;
  char Lower;
};

struct Logos {
  
};


// ids are what compose documents, but an id can be concealed with a string.


// use literal pointers duh.
struct Link {
  int idA;
  int idB;

  //title by which the id is represented...
  const char *text;


};
// texts are composed of entries. but entries have text so really an Entry is composed of other entries...
// does an Entry have a canonical title, a set, or not specified... the "names it goes by" are the titles by
// which it is linked variously. Therefore no Entry has a true name. Maybe you must discover them.
// the text of a document is then composed of links to documents, not actual documents.
// but if player is to be creating links then there isn't anything for the document to be composed of yet,
// and if were just links that only had a parent, then there'd be an issue with whether each word is a link, or
// there are just fragments you can work with. Well, each letter may have a link, and each word, and a series of
// tokens, so that means a document is composed of documents, and groups of
// It's not right to say that that they're links, because one linke might be "A" but another "A B",
// Maybe somethings are named but not all.

// A name is purely optional. Letters will have names, but not necessarily everything. Somethings will acquire names
// there's still the issue of links. the cover a range of texts.
// space is interesting, does it have a name, because if so then we can't use it by it's name if we want " "
// problem with using pointers is that they aren't two way....
// things should go down levels, so the texts are words, but each of those words are composed of letters..

// Build a document up out of contents and links (that is, pointers to other content)
struct Text {
  int id;
  const char *name;
  Text *texts[4];
  // links should go both way, so for an entry it's all ordered from: here, to: there.
};

struct Console {
  //  Document documentViewed;
};

int main() {
  
  
  // Each letter, symbol, word, and also "come and see" is biblical, "see...touch" are grouped under five senses
  const char *text1 = "Come and see, hear, smell, taste, and touch.";
  // Again, biblical, your name, three conditions, pronouns "who, you, my"
  const char *text2 = "Who is like you, my Shai Faux, deaf, dumb, and blind?";
  // compose a tutorial section, introduce nouns, verbs, pronouns, articels, conjuctions, etcetera.

  // it's a very circular way to define things, but since they're pointers it's just waiting for that data to get
  // filled in down the road.
  
  Text a = {};
  Text *aptr = &a;

  Text b = {};
  Text *bptr = &b;

  a.id = 1;
  b.id = 2;

  a.name = "A";
  b.name = "B";


  //  a.texts[0];
  
  Text father = {};

  // so we compose it as "abba", the problem is that's the name of those texts, not the texts themselves...
  // this is hella corrupting the data...
  father.id = 100;
  father.texts[0] = aptr;
  father.texts[1] = bptr;
  father.texts[2] = bptr;
  father.texts[3] = aptr;

  printf("%s%s%s%s\n", father.texts[0]->name, father.texts[1]->name, father.texts[2]->name, father.texts[3]->name);
  printf("%s\n", text2);
  return 0;
}
