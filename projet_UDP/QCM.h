#define NUM_QUESTIONS 2

typedef struct {
  char* question;
   char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
  {
	"What is the capital of France?\nA:Paris\n B:Berlin\nC:Madrid\n D:London\nChoisissez votre reponse parmi A B C ou D\n",
    'A'
  },
  {
    "What is the currency of Japan?\nA:Yen\n B:Dollar\nC:Euro\nD:Won\nChoisissez votre reponse parmi A B C ou D\n",
    'A'
  },
  { “Who wrote the novel ‘1984’?\nA:George Orwell\n B:J.R.R. Tolkien\nC:Mark Twain\nD:Ernest Hemingway\nChoose your answer from A B C or D\n”, ‘A’ },
  { “What is the largest bone in the human body?\nA:Tibia\n B:Femur\nC:Humerus\nD:Skull\nChoose your answer from A B C or D\n”, ‘B’ },
  { “Which planet is the second from the Sun?\nA:Mars\n B:Venus\nC:Earth\nD:Mercury\nChoose your answer from A B C or D\n”, ‘B’ },
  { “What is the name of the phobia that means fear of spiders?\nA:Arachnophobia\n B:Claustrophobia\nC:Agoraphobia\nD:Acrophobia\nChoose your answer from A B C or D\n”, ‘A’ },
  { “Which country has the largest population in the world?\nA:India\n B:China\nC:USA \nD:Indonesia \nChoose your answer from A B C or D \n”, ‘B’ }
  // Add more questions here
};