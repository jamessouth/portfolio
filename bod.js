class Bod {

  

    static getDistAlongSide(max) {
        return Math.floor(Math.random() * (max + 1));
    }

    static getPoint(side, width, height) {
        // console.log(side, width, height);
        switch (side) {
          case 0:
            return [
              0,
              Bod.getDistAlongSide(height),
            ];
          case 1:
            return [
              Bod.getDistAlongSide(width),
              height,
            ];
          case 2:
            return [
              width,
              Bod.getDistAlongSide(height),
            ];
          case 3:
            return [
              Bod.getDistAlongSide(width),
              0,
            ];
          default: return undefined;
        }
      }
    paint(ctx, {width, height}) { // eslint-disable-line


      for (let i = 0; i < 35; i += 1) {

        
        const [startx, starty] = Bod.getPoint(i%4, width, height);
        const [endx, endy] = Bod.getPoint((i+1)%4, width, height);
        
        const grad = ctx.createLinearGradient(startx, starty, endx, endy);
        grad.addColorStop(0, 'rgba(208, 0, 0, .05)');
        grad.addColorStop(0.15, 'transparent');
        grad.addColorStop(0.68, 'transparent');
        grad.addColorStop(0.81, 'rgba(106, 91, 110, .07)');
        grad.addColorStop(0.89, 'transparent');
        grad.addColorStop(0.90, 'transparent');
        grad.addColorStop(0.95, 'rgba(255, 238, 136, .12)');
        grad.addColorStop(1, 'rgba(255, 238, 136, .13)');
        ctx.globalCompositeOperation = 'color-burn';
        ctx.fillStyle = grad;
        ctx.fillRect(0, 0, width, height);


      }
    }
  }
  registerPaint('bod', Bod); // eslint-disable-line