#define NUM_QUESTIONS 5

typedef struct {
  char* question;
  char* optionA;
  char* optionB;
  char* optionC;
  char* optionD;
  char correctOption;
} Question;

Question questions[NUM_QUESTIONS] = {
  {
    "What is the capital of France?",
    "Paris",
    "Berlin",
    "Madrid",
    "London",
    'A'
  },
  {
    "What is the currency of Japan?",
    "Yen",
    "Dollar",
    "Euro",
    "Won",
    'A'
  },
  // Add more questions here
};
