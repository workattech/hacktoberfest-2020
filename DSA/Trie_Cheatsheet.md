# Trie	

        Short Intro: It is used for faster searching of a string in a set of string(Dictionary).		
        Time complexity: O(N), where N is the length of the Searched String.	
        Space Complexity: O(M), where M is the number Keys in the Trie.	
        Disadvantage: Require lots of space.(Not Space Efficient).

        It is efficient for the following operations on words in a dictionary:

        1) Search. 			Time Complexity: O(N), where N is the length of the Searched String.
        2) Insert. 			Time Complexity: O(N), where N is the length of the Searched String.
        3) Delete. 			Time Complexity: O(N), where N is the length of the Searched String.
        4) Prefix Search.		Time Complexity: O(N), where N is the size of the prefix.
        5) Lexicographical Ordering of Words.	Time Complexity: O(M), where M is the number Keys in the Trie.

#  Time complexities Comparision with Hashing:

                                                       Trie			  				 Hashing
                                              
        1)	Search			    Theta(word_length) in worst case.		          Theta(word_length) in average case.
        
        2)	Insert			    Theta(word_length) in worst case.		          Theta(word_length) in average case.
        
        3)	Delete			    Theta(word_length) in worst case.		          Theta(word_length) in average case.
        
        4)	Prefix Search		    Theta(prefix_length) in worst case.		          Not Supported
        
        5)	Lexicographical		    Theta(Output_length) in worst case.		          Not Supported	
                Ordering
  
  For more info:https://www.geeksforgeeks.org/trie-insert-and-search/
