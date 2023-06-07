FROM nginx

RUN echo hello


COPY Conf /etc/nginx

COPY html /usr/share/nginx/html
COPY html/styles /usr/share/nginx/html/styles
COPY html/scripts /usr/share/nginx/html/scripts
COPY html/images /usr/share/nginx/html/images

#setup docker user
RUN apt-get update && \
      apt-get -y install sudo


EXPOSE 80


