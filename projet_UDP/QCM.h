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
  // Add more questions here
};