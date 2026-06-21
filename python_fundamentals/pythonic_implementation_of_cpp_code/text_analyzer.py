import re
from collections import Counter

def analyze_text_frequencies(text: str, top_k: int = 5) -> list:
    """
    Cleans text, tokenizes it, and returns the top_k most frequent words.
    This demonstrates the high-level equivalent of a C++ STL unordered_map.
    """

    text = text.lower()
    
    # Use regular expressions to extract only alphanumeric words 
    # (This replaces the manual loop and isalnum() check from C++)
    words = re.findall(r'\b[a-z0-9]+\b', text)
    
    # Counter automatically creates a frequency hash map and sorts it
    word_counts = Counter(words)
    
    # Return the most common elements
    return word_counts.most_common(top_k)

if __name__ == "__main__":
    # The same sample corpus used in the C++ analyzer
    corpus = (
        "C++ is powerful. C++ is fast. Python is great for AI, "
        "but C++ builds the core. AI needs data, data needs processing."
    )
    
    print("--- Python NLP Text Analyzer ---")
    print("-" * 32)
    
    top_words = analyze_text_frequencies(corpus, top_k=5)
    
    for word, count in top_words:
        # ljust(10) aligns the text neatly, just like printf in C++
        print(f"{word.ljust(10)} : {count}")import re
from collections import Counter

def analyze_text_frequencies(text: str, top_k: int = 5) -> list:
    """
    Cleans text, tokenizes it, and returns the top_k most frequent words.
    This demonstrates the high-level equivalent of a C++ STL unordered_map.
    """

    text = text.lower()
    
    # Use regular expressions to extract only alphanumeric words 
    # (This replaces the manual loop and isalnum() check from C++)
    words = re.findall(r'\b[a-z0-9]+\b', text)
    
    # Counter automatically creates a frequency hash map and sorts it
    word_counts = Counter(words)
    
    # Return the most common elements
    return word_counts.most_common(top_k)

if __name__ == "__main__":
    # The same sample corpus used in the C++ analyzer
    corpus = (
        "C++ is powerful. C++ is fast. Python is great for AI, "
        "but C++ builds the core. AI needs data, data needs processing."
    )
    
    print("--- Python NLP Text Analyzer ---")
    print("-" * 32)
    
    top_words = analyze_text_frequencies(corpus, top_k=5)
    
    for word, count in top_words:
        # ljust(10) aligns the text neatly, just like printf in C++
        print(f"{word.ljust(10)} : {count}")import re
from collections import Counter

def analyze_text_frequencies(text: str, top_k: int = 5) -> list:
    """
    Cleans text, tokenizes it, and returns the top_k most frequent words.
    This demonstrates the high-level equivalent of a C++ STL unordered_map.
    """

    text = text.lower()
    
    # Use regular expressions to extract only alphanumeric words 
    # (This replaces the manual loop and isalnum() check from C++)
    words = re.findall(r'\b[a-z0-9]+\b', text)
    
    # Counter automatically creates a frequency hash map and sorts it
    word_counts = Counter(words)
    
    # Return the most common elements
    return word_counts.most_common(top_k)

if __name__ == "__main__":
    # The same sample corpus used in the C++ analyzer
    corpus = (
        "C++ is powerful. C++ is fast. Python is great for AI, "
        "but C++ builds the core. AI needs data, data needs processing."
    )
    
    print("--- Python NLP Text Analyzer ---")
    print("-" * 32)
    
    top_words = analyze_text_frequencies(corpus, top_k=5)
    
    for word, count in top_words:
        # ljust(10) aligns the text neatly, just like printf in C++
        print(f"{word.ljust(10)} : {count}")
