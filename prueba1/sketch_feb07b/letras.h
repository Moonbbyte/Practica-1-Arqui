int Asterisco[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,1,0,1,1,0},
  {0,0,0,1,1,1,0,0},
  {0,1,1,1,1,1,1,1},
  {0,0,0,1,1,1,0,0},
  {0,0,1,1,0,1,1,0},
  {0,0,0,0,0,0,0,0}
};
int P[][8]={
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,0,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,0,0,1,1,0},
  {0,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {0,1,1,0,0,0,0,0}
};
int UNO[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,1,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,1,1,1,1,1,1,0}
};
int GUION[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,1,1,1,1,1,1,0},
  {0,1,1,1,1,1,1,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};
int UNO[][8]={
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0}
};

int A[][8]={
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1}
};



int G[][8]={
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {0,0,0,0,0,0,1,1},
  {1,1,1,1,0,0,1,1},
  {1,1,1,1,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0}
};

int U[][8]={
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0}
};

int R[][8]={
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,1},
  {0,1,1,1,0,0,1,1},
  {1,1,1,0,0,0,1,1},
  {1,1,0,0,0,0,1,1}
};

int O[][8]={
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0}
};

int C[][8]={
  {0,1,1,1,1,1,1,0},
  {1,1,1,1,1,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,0,0},
  {1,1,0,0,0,0,0,0},
  {1,1,0,0,0,0,1,1},
  {1,1,1,1,1,1,1,1},
  {0,1,1,1,1,1,1,0}
};

int I[][8]={
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {0,0,0,1,1,0,0,0},
  {1,1,1,1,1,1,1,1},
  {1,1,1,1,1,1,1,1}
};

int N[][8]={
  {1,1,0,0,0,0,1,1},
  {1,1,1,0,0,0,1,1},
  {1,1,1,1,0,0,1,1},
  {1,1,0,1,1,0,1,1},
  {1,1,0,0,1,1,1,1},
  {1,1,0,0,0,1,1,1},
  {1,1,0,0,0,0,1,1},
  {1,1,0,0,0,0,1,1}
};
