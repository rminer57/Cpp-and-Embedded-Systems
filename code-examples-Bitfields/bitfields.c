struct comm_states
{
   unsigned int dev_tx   :1;
   unsigned int dev_rx   :1;
   unsigned int dev_wait :1;
   unsigned int dev_full :1;
};
struct comm_states state_flag;

if (state_flag.dev_rx ==1)
{
   printf("comms device receiving data\n");
   disable_tx();
};