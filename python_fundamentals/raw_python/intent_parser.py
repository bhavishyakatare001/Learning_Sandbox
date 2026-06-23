import string

class IntentParser:
    """
    A lightweight, pure-Python intent parser for routing user commands.
    """
    def __init__(self):
        
        self.intents = {}

    def register_intent(self, intent_name: str, keywords: list):
        """
        Registers a new intent category and its associated trigger words.
        """
        
        self.intents[intent_name] = set(word.lower() for word in keywords)

    def _clean_text(self, text: str) -> list:
        """
        Internal helper to normalize raw input strings.
        """
        text = text.lower()
        
        
        for char in string.punctuation:
            text = text.replace(char, ' ')
        
   
        return text.split()

    def parse(self, user_input: str) -> str:
        """
        Analyzes the input against registered keywords and returns the best matching intent.
        """
        if not user_input or not user_input.strip():
            return "unknown"

        words = self._clean_text(user_input)
        
        best_intent = "unknown"
        max_matches = 0

       
        for intent_name, keyword_set in self.intents.items():
            
            match_count = sum(1 for word in words if word in keyword_set)
            
            
            if match_count > max_matches:
                max_matches = match_count
                best_intent = intent_name

        return best_intent



if __name__ == "__main__":
    
    parser = IntentParser()
    
    
    parser.register_intent("system_action", ["open", "close", "start", "terminal", "run", "execute", "boot"])
    parser.register_intent("mediblitz_query", ["grades", "cgpa", "credits", "university", "schedule", "hub", "syllabus"])
    parser.register_intent("intention_eval", ["score", "interview", "assess", "pipeline", "dynamic", "technical"])

    test_inputs = [
        "Can you open the terminal and execute the script?",
        "What is my current CGPA for the university credits?",
        "Assess this dynamic technical interview score pipeline.",
        "Tell me a random joke about the weather.",
        "   " # Testing empty edge case
    ]

    print("--- Running Intent Parser Tests ---\n")
    for text in test_inputs:
        intent = parser.parse(text)
        print(f"Input:  '{text}'")
        print(f"Result: {intent}\n")