
/* typedef int bool; */
/* #define true 1 */
/* #define fales 0 */

enum PartOfSpeech {
    Noun, Verb, Adjective, Adverb
};

enum Number {
    Singular, Plural
};

enum Person {
    First, Second, Third
};

enum Tense {
    Past, Present, Future
};

struct Word {
    char *word;
    PartOfSpeech pos;
    Number number;
    Person person;
    Tense tense;
};

struct Words {
    // or a pointer?
    Word words[];
};

// A text has n semantic divisions, n lines and columns (columns are specific to regions of lines tho...)
// and are of course a collection of words (characters really)
struct Text {
    
};

// A must point to B, and B must point to A.
struct Chord {
    void *A;
    void *B;
};

Chord Entwine(void *A, void *B) {
    struct Chord result = {};
    result.A = B;
    result.B = A;
    return result;
}
