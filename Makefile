# Download dependencies to the dependencies directory
load:
	@mkdir -p src/deps/ulid
	@mkdir -p src/deps/cee-utils
	@curl https://raw.githubusercontent.com/skeeto/ulid-c/master/ulid.c > src/deps/ulid/ulid.c
	@curl https://raw.githubusercontent.com/skeeto/ulid-c/master/ulid.h > src/deps/ulid/ulid.h
	@git clone https://github.com/cee-studio/cee-utils src/deps/cee-utils
	@sudo rm src/deps/cee-utils/.git -r
