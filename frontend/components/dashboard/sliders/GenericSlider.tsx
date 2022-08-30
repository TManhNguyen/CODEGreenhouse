import Slider, { createSliderWithTooltip, SliderProps } from 'rc-slider';
import { ComponentWrapperProps } from 'rc-slider/lib/createSliderWithTooltip';

type Props = SliderProps & ComponentWrapperProps & {
  title: string,
  subtitle: string
}

const GenericSlider = ({
  title,
  subtitle,
  ...sliderProps
}: Props) => {
  const SliderWithTooltip = createSliderWithTooltip(Slider)
  return (  
    <div className="flex-auto">
      <div className="font-medium">{title}:</div>
      <div className="text-sm font-normal text-gray-500">{subtitle}</div>
      <div className="mx-2">
        <SliderWithTooltip 
          className="my-3"
          included={false}
          {...sliderProps}
        />
      </div>
    </div>
  ) 
}

export default GenericSlider