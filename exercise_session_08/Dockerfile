FROM ubuntu:trusty

RUN apt-get update -q && \
        apt-get install -y -q --no-install-recommends \
        g++ make python3.9 python3-pip
FROM python:3

RUN pip install --no-cache-dir --upgrade pip && \
    pip install --no-cache-dir numpy matplotlib

COPY . /poisson_solver

WORKDIR /poisson_solver

RUN make all

CMD ["./main", "python3 ./output/plot.py"]