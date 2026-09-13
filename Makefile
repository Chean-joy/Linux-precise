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
condition_var:condition_var.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

unnamed_sem_bin_process:unnamed_sem_bin_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
thread_pool_test:thread_pool_test.c
	-$(CC) -o $@ $^ `pkg-config --cflags --libs glib-2.0`
	-./$@
	-rm ./$@

unnamed_sem_count_thread:unnamed_sem_count_thread.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
named_sem_bin_process:named_sem_bin_process.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@

Pthread_create_test:Pthread_create_test.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
Phread_mutex:Phread_mutex.c
	-$(CC) -o $@ $^
	-./$@
	-rm ./$@
