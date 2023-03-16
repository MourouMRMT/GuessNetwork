#define NUM_QUESTIONS 2

typedef struct {
  char* question;
   char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
  {
	"What is the capital of France? \n A:Paris \n B:Berlin \n C:Madrid \n D:London \n Choisissez votre reponse parmi A B C ou D \n",
    "A"
  },
  {
    "What is the currency of Japan? \n A:Yen \n B:Dollar \n C:Euro \n D:Won \n Choisissez votre reponse parmi A B C ou D \n",
    "A"
  },
  // Add more questions here
};