import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""
        
        #store positives in a set
        self.positives = set()
        file = open(positives, "r")
        for line in file:
            #if line is not a comment 
            if line.startswith(';') == False:
                #omit new line and add to positives
                self.positives.add(line.rstrip("\n"))
        file.close()

        #similar working as positives
        self.negatives = set()
        file = open(negatives, "r")
        for line in file:
            if line.startswith(';') == False:
                self.negatives.add(line.rstrip("\n"))
        file.close()

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""
        
        tokenizer = nltk.tokenize.TweetTokenizer()
        tokens = tokenizer.tokenize(text)
        
        sum = 0
        for word in tokens:
            if word.lower() in self.positives:
                sum += 1
            elif word.lower() in self.negatives:
                sum -= 1
            else:
                continue
        
        return sum
        
