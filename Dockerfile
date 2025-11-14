FROM gcc:13
WORKDIR /app
COPY . .
# Build: prefer Makefile if present, else compile all .cpp
RUN if [ -f Makefile ] || [ -f makefile ]; then make; \
    else g++ -std=c++17 -Wall -O2 -o bank *.cpp; fi
RUN mkdir -p /app/data
ENV BANK_DATA_DIR=/app/data
CMD ["./bank"]
