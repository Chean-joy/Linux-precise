CC := gcc

pthread_datth_test:pthread_datth_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
pthread_cancel_test_delay:pthread_cancel_test_delay.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
pthread_cancel_async_test_:pthread_cancel_async_test_.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
pthread_cancel_disable_test:pthread_cancel_disable_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
race_condition_test:race_condition_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
rwlock_test_writer_unlock:rwlock_test_writer_unlock.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
rwlock_test:rwlock_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
rwlock_hungry_solved:rwlock_hungry_solved.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@