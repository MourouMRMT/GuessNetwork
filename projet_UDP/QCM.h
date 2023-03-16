#define NUM_QUESTIONS 2

typedef struct {
  char* question;
   char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
  {
	"What is the capital of France? \n\t A:Paris \n\t B:Berlin \n\t C:Madrid \n\t D:London \n\t Choisissez votre reponse parmi A B C ou D \n\t",
    "A"
  },
  {
    "What is the currency of Japan? \n\t A:Yen \n\t B:Dollar \n\t C:Euro \n\t D:Won \n\t Choisissez votre reponse parmi A B C ou D \n\t",
    "A"
  },
  // Add more questions here
};